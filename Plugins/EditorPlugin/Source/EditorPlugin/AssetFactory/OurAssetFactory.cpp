// Fill out your copyright notice in the Description page of Project Settings.


#include "OurAssetFactory.h"
#include "../Objects/AssetObject.h"

UOurAssetFactory::UOurAssetFactory()
{
	SupportedClass = UAssetObject::StaticClass();
	
}

bool UOurAssetFactory::CanCreateNew() const
{
	return true;
}

bool UOurAssetFactory::ShouldShowInNewMenu() const
{
	return true;
}

UObject* UOurAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
                                            UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UAssetObject>(InParent, InClass, InName, Flags);
}
