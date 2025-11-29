#include "AC_Tracer_01.h"

UAC_Tracer_01::UAC_Tracer_01(){
	PrimaryComponentTick.bCanEverTick = true;

}


void UAC_Tracer_01::BeginPlay(){
	Super::BeginPlay();
	
}

void UAC_Tracer_01::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction){
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////

//// Trace_typeA returns an actor 
AActor* UAC_Tracer_01::Trace_typeA(FVector start, FVector end, bool& Result) {
	GetWorld()->LineTraceSingleByChannel(
		Hit,
		start,
		end,
		TraceChannelProperty,
		QueryParameters
	);
	DrawDebugLine(
		GetWorld(),
		start,
		end,
		Hit.bBlockingHit ? FColor::Blue : FColor::Red,
		false,
		5.0f,
		0,
		10.0f
	);

	UE_LOG(LogTemp, Log, TEXT(">> KTX --- Trace_typeA : %s to %s"), *start.ToCompactString(), *end.ToCompactString());

	Result = (Hit.bBlockingHit) && (IsValid(Hit.GetActor()));

	if (Result) {
		UE_LOG(LogTemp, Log, TEXT(">> KTX --- Trace_typeA -- hit actor: %s"), *Hit.GetActor()->GetName());
	}

	return Hit.GetActor();
}

//// Trace_typeB activates CPPI_Activation interface on actor
void UAC_Tracer_01::Trace_typeB(FVector start, FVector end, FString name, int ID) {

	GetWorld()->LineTraceSingleByChannel(Hit, start, end, TraceChannelProperty, QueryParameters);

	DrawDebugLine(
		GetWorld(), start, end,
		Hit.bBlockingHit ? FColor::Blue : FColor::Red, false,
		5.0f, 0, 10.0f
	);


	UE_LOG(LogTemp, Log, TEXT(">> KTX --- Trace_typeB : %s to %s"), *start.ToCompactString(), *end.ToCompactString());

	if (Hit.bBlockingHit && IsValid(Hit.GetActor())) {
		UE_LOG(LogTemp, Log, TEXT(">> KTX --- Trace_typeB --  hit actor: %s"), *Hit.GetActor()->GetName());
		if (Hit.GetActor()->GetClass()->ImplementsInterface(UCPPI_Activation::StaticClass())) {
			ICPPI_Activation::Execute_CPPI_Activation_Check(Hit.GetActor()); // activate event
			ICPPI_Activation::Execute_CPPI_Activation_Recive(Hit.GetActor(), name, ID); // activate event and send data
		}

	} else {
		UE_LOG(LogTemp, Log, TEXT("KTX ---No Actors were hit"));
	}
}

//// Trace_typeC activates CPPI_CheckKey interface on actor, and returns id as integer (int& keyID)
void UAC_Tracer_01::Trace_typeC(FVector start, FVector end, FString name, int& keyID) {

	GetWorld()->LineTraceSingleByChannel(Hit, start, end, TraceChannelProperty, QueryParameters);
	DrawDebugLine(
		GetWorld(), start, end,
		Hit.bBlockingHit ? FColor::Blue : FColor::Red, false,
		5.0f, 0, 10.0f
	);


	UE_LOG(LogTemp, Log, TEXT(">> KTX --- Trace_typeC : %s to %s"), *start.ToCompactString(), *end.ToCompactString());

	Key_ID_01 = -1;
	if (Hit.bBlockingHit && IsValid(Hit.GetActor())) {
		UE_LOG(LogTemp, Log, TEXT(">> KTX --- Trace_typeC --  hit actor: %s"), *Hit.GetActor()->GetName());

		if (Hit.GetActor()->GetClass()->ImplementsInterface(UCPPI_CheckKey::StaticClass())) {

			ICPPI_CheckKey::Execute_CPPI_GetKeyID(Hit.GetActor(), Key_ID_01); // call function and revive data
			ICPPI_CheckKey::Execute_CPPI_CheckandGetID(Hit.GetActor(), name, Key_ID_01); // call function and send/receive data
			UE_LOG(LogTemp, Warning, TEXT(" KTX -- Trace_typeC --  Return ID: %d"), Key_ID_01);

			// example of call function and send/receive multiple data
			int tempID = 0;
			bool tempBool = false;
			FString tempMessage = "Damaged";

			ICPPI_CheckKey::Execute_CPPI_MultipleValueExample(Hit.GetActor(), " Red Team ", true, tempID, tempBool, tempMessage);

			UE_LOG(LogTemp, Warning, TEXT(" KTX -- Trace_typeC --  multiple data tempID: %d"), tempID);
			UE_LOG(LogTemp, Warning, TEXT(" KTX -- Trace_typeC --  multiple data tempBool: %s"), (tempBool ? TEXT("Has Damage") : TEXT("No Damage")));
			UE_LOG(LogTemp, Warning, TEXT(" KTX -- Trace_typeC --  multiple data tempMessage: %s"), *tempMessage);

		}

	} else {  
		UE_LOG(LogTemp, Log, TEXT("KTX ---No Actors were hit"));
	}
	keyID = Key_ID_01;
}


//// Trace_typeD activates CPPI_ItemTools interface on actor, and returns id as integer (int& keyID)
void UAC_Tracer_01::Trace_typeD(FVector start, FVector end, FString data, int& keyID){
	GetWorld()->LineTraceSingleByChannel(Hit, start, end, TraceChannelProperty, QueryParameters);
	DrawDebugLine(
		GetWorld(), start, end,
		Hit.bBlockingHit ? FColor::Blue : FColor::Red, false,
		5.0f, 0, 10.0f
	);

	if ((Hit.bBlockingHit) && (IsValid(Hit.GetActor()))) { 
		UE_LOG(LogTemp, Log, TEXT(">> KTX --- Trace_typeD -- hit actor: %s"), *Hit.GetActor()->GetName());

		ICPPI_ItemTools* ItemToolInterface = Cast<ICPPI_ItemTools>(Hit.GetActor()); // cast to C++ interface CPPI_ItemTools
		if (ItemToolInterface) {
			ItemToolInterface->CPPI_Item_Activate();
			ItemToolInterface->CPPI_Item_ActivateWithData(data);// send data 
			//ItemToolInterface->CPPI_ActivateWithID(4);// send data 
			keyID = ItemToolInterface->CPPI_Item_GetID();// receive data 
			UE_LOG(LogTemp, Warning, TEXT(" KTX -- Trace_typeD --  Return ID: %d"), keyID);
		}
	}else {
		UE_LOG(LogTemp, Log, TEXT("KTX ---No Actors were hit"));
	}
}


