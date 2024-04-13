// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Editor/UnrealEd/Classes/Factories/Factory.h"
#include "OurAssetFactory.generated.h"

/**
 * 
 */
UCLASS()
class EDITORPLUGIN_API UOurAssetFactory : public UFactory
{
	GENERATED_BODY()

public:
	UOurAssetFactory();
	virtual bool CanCreateNew() const override;
	//virtual bool ShouldShowInNewMenu() const override;
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	
};
