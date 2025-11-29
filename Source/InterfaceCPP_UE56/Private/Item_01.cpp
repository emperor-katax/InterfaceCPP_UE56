#include "Item_01.h"

AItem_01::AItem_01(){
	PrimaryActorTick.bCanEverTick = true;
}

void AItem_01::BeginPlay(){
	Super::BeginPlay();
	
}

void AItem_01::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
}


///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
//// CPPI_ItemTools interface implementation

 void AItem_01::CPPI_Item_Hidden(bool item_visibility = true) {
	if (item_visibility) HideItem(true);
	else HideItem(false);
	// HideItem(item_visibility); // <-- simple !
}

void AItem_01::CPPI_Item_Activate() {
	// code ..
	ActivateItem();
}

void AItem_01::CPPI_Item_ActivateWithData(FString data = "") {
	CheckAndActivation(data);
}

void AItem_01::CPPI_ActivateWithID(int id) {
	ActivationByID(ItemID);
}

int AItem_01::CPPI_Item_GetID() {
	return ItemID;
}


// abstract method implementation
//void AItem_01::CPPI_Item_GetCount(int item_count) {
//
//}



