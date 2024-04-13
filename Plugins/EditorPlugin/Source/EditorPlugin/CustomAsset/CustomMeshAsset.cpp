#include "CustomMeshAsset.h"
#include "EditorPlugin/Objects/MeshAsset.h"

FCustomMeshAsset::FCustomMeshAsset(EAssetTypeCategories::Type Type)
{
	AssetCategory=Type;
}

FText FCustomMeshAsset::GetName() const
{
	return FText::FromString("MeshAsset");
}

FColor FCustomMeshAsset::GetTypeColor() const
{
	return FColor::Yellow;
}

UClass* FCustomMeshAsset::GetSupportedClass() const
{
	return UMeshAsset::StaticClass();
}

void FCustomMeshAsset::OpenAssetEditor(const TArray<UObject*>& InObjects,
	TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	FAssetTypeActions_Base::OpenAssetEditor(InObjects, EditWithinLevelEditor);
}

uint32 FCustomMeshAsset::GetCategories()
{
	return AssetCategory;
}
