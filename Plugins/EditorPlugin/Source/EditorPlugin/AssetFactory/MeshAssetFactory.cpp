#include "MeshAssetFactory.h"

#include "EditorPlugin/Objects/MeshAsset.h"

UMeshAssetFactory::UMeshAssetFactory()
{
	SupportedClass=UMeshAsset::StaticClass();
}

bool UMeshAssetFactory::CanCreateNew() const
{
	return true;
}

bool UMeshAssetFactory::ShouldShowInNewMenu() const
{
	return true;
}

UObject* UMeshAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UMeshAsset>(InParent,InClass,InName,Flags);
}
