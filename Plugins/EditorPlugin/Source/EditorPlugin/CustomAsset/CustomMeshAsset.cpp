#include "CustomMeshAsset.h"

#include "EditorPlugin/Editor/MeshAssetToolkit.h"
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
	//FAssetTypeActions_Base::OpenAssetEditor(InObjects, EditWithinLevelEditor);
	const EToolkitMode::Type ToolKitModeType = EditWithinLevelEditor ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for(auto ObjectIterator = InObjects.CreateConstIterator(); ObjectIterator;++ObjectIterator )
	{
		if(UMeshAsset* OurAsset = Cast<UMeshAsset>(*ObjectIterator))
		{
			const TSharedRef<FMeshAssetToolkit>MeshAssetToolkit = MakeShareable(new  FMeshAssetToolkit);
			MeshAssetToolkit->Init(ToolKitModeType,EditWithinLevelEditor,OurAsset);
		}
	}
}

uint32 FCustomMeshAsset::GetCategories()
{
	return AssetCategory;
}
