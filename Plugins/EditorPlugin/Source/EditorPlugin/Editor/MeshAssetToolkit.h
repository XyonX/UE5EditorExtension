#pragma once
#include "CoreMinimal.h"
#include "Toolkits/AssetEditorToolkit.h"


class UMeshAsset;

class EDITORPLUGIN_API FMeshAssetToolkit final : public FAssetEditorToolkit
{
public:
	//For the name and stuffs of the editor
	virtual FName GetToolkitFName() const override {return FName("MeshAssetToolkit");};
	virtual FText GetBaseToolkitName() const override{return  FText::FromString("MeshAssetToolkit");};
	virtual FString GetWorldCentricTabPrefix() const override{ return TEXT("M_Toolkit");};
	virtual FLinearColor GetWorldCentricTabColorScale() const override{return FLinearColor(1.0,1.0,1.0,1.0);};

	//For registering
	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;

	void Init(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, UObject* InAssets);

	TSharedRef<SDockTab> SpawnDetailTab(const FSpawnTabArgs& SpawnTabArgs) const;


	//Variables
	
	//TObjectPtr<UEdGraph> EdGraph;
	inline static FName PreviewObjectEditorLayoutName{"PreviewObjectEditorLayout"};
	inline static FName PreviewObjectEditorDetailTabName{"PreviewObjectEditorDetailTab"};
	inline static FName PreviewObjectEditorPreviewSceneTabName{"PreviewObjectEditorPreviewSceneTab"};

	TObjectPtr<UMeshAsset> EditingPreviewObject = nullptr;
	
	//const TSharedRef<IDetailsView> DetailsViewWidget;
	
};
