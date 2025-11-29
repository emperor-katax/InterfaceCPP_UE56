#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "CPPI_Activation.h" // include interface header file
#include "CPPI_CheckKey.h" // include interface header file
#include "CPPI_ItemTools.h" // include interface header file

#include "AC_Tracer_01.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERFACECPP_UE56_API UAC_Tracer_01 : public UActorComponent{
	GENERATED_BODY()

public:	

	UAC_Tracer_01();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(EditAnywhere, Category = "Trace Collision")
	TEnumAsByte<ECollisionChannel> TraceChannelProperty = ECC_Pawn;

	UFUNCTION(BlueprintPure, Category = "Trace Functions")
	AActor* Trace_typeA(FVector start, FVector end, bool& Result);

	UFUNCTION(BlueprintCallable, Category = "Trace Functions")
	void Trace_typeB(FVector start, FVector end, FString name, int ID);

	UFUNCTION(BlueprintCallable, Category = "Trace Functions")
	void Trace_typeC(FVector start, FVector end, FString name, int& keyID);

	UFUNCTION(BlueprintCallable, Category = "Trace Functions")
	void Trace_typeD(FVector start, FVector end, FString data, int& keyID);


	int Key_ID_01 = -1;
	//int Result; // <-- problem ! - reserved variable/property name

	FHitResult Hit;
	FVector TraceStart = FVector::ZeroVector;
	FVector TraceEnd = FVector::ZeroVector;

	// Structure that defines parameters passed into collision function
	FCollisionQueryParams QueryParameters;
};

/*

Line Trace in C++
https://dev.epicgames.com/community/snippets/2rR/simple-c-line-trace-collision-query
https://forums.unrealengine.com/t/how-would-i-use-line-trace-in-c/275534/8
https://www.youtube.com/watch?v=GfsnOiwKJcY
https://www.youtube.com/watch?v=qACoBfFIe7o
https://www.youtube.com/watch?v=Ii0rw9p6hbI
https://www.youtube.com/watch?v=D6G8_PU8ZFY

UE log
https://unrealcommunity.wiki/logging-lgpidy6i
https://dev.epicgames.com/documentation/en-us/unreal-engine/logging-in-unreal-engine

Collision in C++
https://dev.epicgames.com/documentation/en-us/unreal-engine/quick-start-guide-to-components-and-collision-in-unreal-engine-cpp
https://forums.unrealengine.com/t/collision-detection-in-c/335962/10
https://forums.unrealengine.com/t/collision-presets-and-ccd-in-c/75426/7

https://www.youtube.com/watch?v=0ZvAnUTodfI
https://www.youtube.com/watch?v=MFZ51eHFB_A
*/