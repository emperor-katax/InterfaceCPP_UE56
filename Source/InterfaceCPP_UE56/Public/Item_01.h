#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPI_ItemTools.h"
#include "Item_01.generated.h"

UCLASS()
class INTERFACECPP_UE56_API AItem_01 : public AActor, public ICPPI_ItemTools{
	GENERATED_BODY()
	
public:	
	AItem_01();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Item Property")
	int ItemID;

	UFUNCTION(BlueprintImplementableEvent, Category = "Item Tools - event")
	void ActivateItem();

	UFUNCTION(BlueprintImplementableEvent, Category = "Item Tools - event")
	void CheckAndActivation(const FString& Message);

	UFUNCTION(BlueprintImplementableEvent, Category = "Item Tools - event")
	void ActivationByID(int id);

	UFUNCTION(BlueprintImplementableEvent, Category = "Item Tools - event")
	void HideItem(bool HideObject);

	// C++ pure interface - ICPPI_ItemTools override 
	virtual void CPPI_Item_Hidden(bool item_visibility) override;
	virtual void CPPI_Item_Activate() override;
	virtual void CPPI_Item_ActivateWithData(FString data) override;
	virtual void CPPI_ActivateWithID(int id) override;
	virtual int CPPI_Item_GetID() override;

	// virtual void CPPI_Item_GetCount(int item_count); // abstract method


protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
