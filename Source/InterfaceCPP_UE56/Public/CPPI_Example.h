#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CPPI_Example.generated.h"

UINTERFACE(MinimalAPI)
class UCPPI_Example : public UInterface{
	GENERATED_BODY()
};


class INTERFACECPP_UE56_API ICPPI_Example{
	GENERATED_BODY()

public:
	// BlueprintImplementableEvent <-- can not be overridden in C++, but can be overridden in any Blueprint class.

	// ////////////////////////////////////////////////////////////////////////////////////////////
	// //////////////////////////////////////////////////////////////////////////////// VOID //////
	// interface event and function with void

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "C++ Interfaces - Void")
	void InterfaceVoid_I(int ID); // interface event

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "C++ Interfaces - Void")
	void InterfaceVoid_II(const FString& Password); // <-- use const and & for data type -> interface event		

	//// issues 
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "C++  Interface")
	//void InterfaceVoid_II_01(FString ID); //<-- not working, parameter data type is a class itself

	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "C++  Interface")
	//void InterfaceVoid_II_02(FString Password); //<-- not working, parameter data type is a class itself		

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "C++ Interfaces - Void")
	void InterfaceVoid_III(const FString& Password, const int& ID_Pass); // interface event


	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "C++ Interfaces - Void")
	void InterfaceVoid_IV(int& ID); // interface function

	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "C++  Interface")
	//void Interact_mode_IV_01(const int& ID); // <--- works as well

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "C++ Interfaces - Void")
	void InterfaceVoid_V(const FString& password, const int& ID_Pass, FString& name, int& ID_New); // interface function  

	// ////////////////////////////////////////////////////////////////////////////////////////////
	// /////////////////////////////////////////////////////////////////////////////// RETURN /////
	// interface function with return value

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "C++ Interfaces - with Return")
	int InterfaceReturnValue_TypeA();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "C++ Interfaces - with Return")
	int InterfaceReturnValue_TypeB();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "C++ Interfaces - with Return")
	const int InterfaceReturnValue_TypeC();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "C++ Interfaces - with Return")
	const int InterfaceReturnValue_TypeD();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "C++ Interfaces - with Return")
	const FString InterfaceReturnValue_TypeE();

	//

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "C++ Interfaces - with Return")
	int InterfaceReturnValue_param_A(FString& password);

	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "C++  Interface")
	//int InterfaceReturnsValue_param_A_01(FString password); //<-- not working, parameter data type is a class itself

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "C++ Interfaces - with Return")
	int InterfaceReturnValue_param_B(const FString& password); // <-- use const and &

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "C++ Interfaces - with Return")
	int InterfaceReturnValue_param_C(const FString& password, const int& ID_Pass, FString& name, int& ID_New);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "C++ Interfaces - with Return")
	const FString InterfaceReturnValue_param_D(const FString& password, const int& ID_Pass, FString& name, int& ID_New);

};

// UE interface
// https://dev.epicgames.com/community/learning/tutorials/bLXe/interfaces-bp-c
// https://dev.epicgames.com/documentation/en-us/unreal-engine/implementing-blueprint-interfaces-in-unreal-engine?application_version=5.6
// https://dev.epicgames.com/documentation/en-us/unreal-engine/interfaces-in-unreal-engine?application_version=5.6
// https://unreal.gg-labs.com/wiki-archives/macros-and-data-types/interfaces-in-c++
// https://forums.unrealengine.com/t/how-to-call-interface-method-from-c/494361/5
// https://exiin.com/blog/unreal-c-interface-and-what-to-do-with-it/


