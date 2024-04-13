#pragma once
#include "CoreMinimal.h"
#include "Toolkits/AssetEditorToolkit.h"


class EDITORPLUGIN_API FCustomAssetToolkit final : public FAssetEditorToolkit
{
public:

	//For the name and stuffs of the editor
	virtual FName GetToolkitFName() const override {return FName("Editor Toolkit");};
	virtual FText GetBaseToolkitName() const override{return  FText::FromString("Editor Toolkit");};
	virtual FString GetWorldCentricTabPrefix() const override{ return TEXT("M_Toolkit");};
	virtual FLinearColor GetWorldCentricTabColorScale() const override{return FLinearColor(1.0,1.0,1.0,1.0);};

public:
	//The Main function to register and unregister tab
	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;


	//This function is not a virtual function, does not contain pattern matching, and is a public function called by external sources
	void InitializeAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, UObject* InAssets);

private:
	// for the details pannel
	TSharedRef<SDockTab> SpawnDetailTab(const FSpawnTabArgs& SpawnTabArgs) const;
	TObjectPtr<UEdGraph> EdGraph;
};
