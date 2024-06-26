﻿#include "OurAsset.h"

#include "EditorPlugin/Editor/CustomAssetToolkit.h"
#include "EditorPlugin/Objects/AssetObject.h"

FAssetTypeActions_OurAssets::FAssetTypeActions_OurAssets(EAssetTypeCategories::Type Type)
{

	MyAssetCategory = Type;
	
}

FText FAssetTypeActions_OurAssets::GetName() const
{
	return NSLOCTEXT("Editor", "Out Assets Name", "CustomAsset");
}

FColor FAssetTypeActions_OurAssets::GetTypeColor() const
{
	return FColor::Red;
}

UClass* FAssetTypeActions_OurAssets::GetSupportedClass() const
{
	return UAssetObject::StaticClass();
}

void FAssetTypeActions_OurAssets::OpenAssetEditor(const TArray<UObject*>& InObjects,
	TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	//FAssetTypeActions_Base::OpenAssetEditor(InObjects, EditWithinLevelEditor);
	const EToolkitMode::Type ToolKitModeType = EditWithinLevelEditor ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;
	
	for (auto ObjectIterator = InObjects.CreateConstIterator(); ObjectIterator; ++ObjectIterator)
	{
		if (UAssetObject* OurAsset = Cast<UAssetObject>(*ObjectIterator))
		{
			const TSharedRef<FCustomAssetToolkit> AssetEditorToolKit = MakeShareable(new FCustomAssetToolkit());
			AssetEditorToolKit->InitializeAssetEditor(ToolKitModeType, EditWithinLevelEditor, OurAsset);
		}
	}
}

uint32 FAssetTypeActions_OurAssets::GetCategories()
{
	return MyAssetCategory;
}




