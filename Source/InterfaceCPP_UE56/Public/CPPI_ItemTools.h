#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CPPI_ItemTools.generated.h"


UINTERFACE(MinimalAPI)
class UCPPI_ItemTools : public UInterface{
	GENERATED_BODY()
};

UENUM(BlueprintType)
enum ENItem_Active {
	Activate,
	Disable
};


class INTERFACECPP_UE56_API ICPPI_ItemTools{
	GENERATED_BODY()

public:
	// BP interface ////////////////////////////////
	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "C++ Interface - ItemTools")
	//void CPPI_Item_ShowName(const FString& name);


	// pure C++ interface //////////////////////////////
	
	// -- approaches
	// -- approach 1 - all data by using 1 interface
	virtual void CPPI_Item_InterfaceSupport(
		ENItem_Active item_activation,
		int item_id,
		bool item_visibility,
		int item_count,
		float item_matparam_01, float item_matparam_02, float item_matparam_03
	);

	// -- approach 2 - group interfaces depends on tasks/data
	virtual void CPPI_Item_Activation(ENItem_Active item_activation);
	virtual void CPPI_Item_Setup(
		int item_id,
		bool item_visibility,
		int item_count,
		float item_matparam_01, float item_matparam_02, float item_matparam_03
	);

	// -- approach 3 - make unique interface for each task/data
	virtual void CPPI_Item_ActivateWithEnum(ENItem_Active item_activation);
	virtual void CPPI_Item_ActivateWithData(FString data);
	virtual void CPPI_Item_Activate();
	virtual void CPPI_Item_Hide();
	virtual void CPPI_Item_UnHide();
	virtual void CPPI_Item_Hidden(bool item_visibility);
	virtual void CPPI_ActivateWithID(int item_id);
	virtual int CPPI_Item_GetID();

	
	// //////////////////////////////////////////////////////////////
	// -- abstract method

	//virtual void CPPI_Item_GetCount(int item_count) = 0; // abstract method <-- MUST be implemented in child classes
};