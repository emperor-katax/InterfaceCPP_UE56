#include "CPPI_ItemTools.h"

void ICPPI_ItemTools::CPPI_Item_InterfaceSupport(ENItem_Active item_activation, int item_id, bool item_visibility, int item_count, float item_matparam_01, float item_matparam_02, float item_matparam_03){}

void ICPPI_ItemTools::CPPI_Item_Activation(ENItem_Active item_activation){}

void ICPPI_ItemTools::CPPI_Item_Setup(int item_id, bool item_visibility, int item_count, float item_matparam_01, float item_matparam_02, float item_matparam_03){}


void ICPPI_ItemTools::CPPI_Item_ActivateWithEnum(ENItem_Active item_activation){}
void ICPPI_ItemTools::CPPI_Item_ActivateWithData(FString data){}
void ICPPI_ItemTools::CPPI_Item_Activate(){}
void ICPPI_ItemTools::CPPI_Item_Hide(){}
void ICPPI_ItemTools::CPPI_Item_UnHide(){}
void ICPPI_ItemTools::CPPI_Item_Hidden(bool item_visibility){}
void ICPPI_ItemTools::CPPI_ActivateWithID(int item_id){}

int ICPPI_ItemTools::CPPI_Item_GetID(){
	return -1;
}


