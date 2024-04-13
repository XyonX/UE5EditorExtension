// Copyright Epic Games, Inc. All Rights Reserved.

#include "EditorPlugin.h"
#include "AssetToolsModule.h"
#include "CustomAsset/CustomMeshAsset.h"
#include "CustomAsset/OurAsset.h"

#define LOCTEXT_NAMESPACE "FEditorPluginModule"



void FEditorPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	RegisterAssetsAction();
}

void FEditorPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

void FEditorPluginModule::RegisterAssetsAction()
{
	IAssetTools& AssetToolModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	const auto Category = AssetToolModule.RegisterAdvancedAssetCategory(FName(TEXT("CustomAssetKey")), NSLOCTEXT("Editor", "Our Category name", "CustomAssets"));

	//creating the custom asset 
	const TSharedPtr<FAssetTypeActions_OurAssets> AssetsTypeAction = MakeShareable(new FAssetTypeActions_OurAssets(Category));
	AssetToolModule.RegisterAssetTypeActions(AssetsTypeAction.ToSharedRef());

	//Creating the custom mesh asset

	const TSharedPtr<FCustomMeshAsset> MeshAssetAction = MakeShareable(new FCustomMeshAsset(Category));
	AssetToolModule.RegisterAssetTypeActions(MeshAssetAction.ToSharedRef());
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEditorPluginModule, EditorPlugin)