#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CPPI_Activation.generated.h"

UINTERFACE(MinimalAPI)
class UCPPI_Activation : public UInterface{
	GENERATED_BODY()
};


class INTERFACECPP_UE56_API ICPPI_Activation{
	GENERATED_BODY()


public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "C++ Interface - Activation")
	void CPPI_Activation_Check();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "C++ Interface - Activation")
	void CPPI_Activation_Recive(const FString& Message, const int& ID);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "C++ Interface - Activation")
	void CPPI_Activation_Hide(bool HideObject);

}; 

// UE interface
// https://dev.epicgames.com/community/learning/tutorials/bLXe/interfaces-bp-c
// https://dev.epicgames.com/documentation/en-us/unreal-engine/implementing-blueprint-interfaces-in-unreal-engine?application_version=5.6
// https://dev.epicgames.com/documentation/en-us/unreal-engine/interfaces-in-unreal-engine?application_version=5.6
// https://unreal.gg-labs.com/wiki-archives/macros-and-data-types/interfaces-in-c++
// https://forums.unrealengine.com/t/how-to-call-interface-method-from-c/494361/5
// https://exiin.com/blog/unreal-c-interface-and-what-to-do-with-it/

