#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "MeshAssetFactory.generated.h"


UCLASS()
class EDITORPLUGIN_API UMeshAssetFactory : public UFactory
{
	GENERATED_BODY()
	
public:
	
	UMeshAssetFactory();
	virtual bool CanCreateNew() const override;
	virtual bool ShouldShowInNewMenu() const override;
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};