#pragma once
#include "AssetTypeActions_Base.h"


class EDITORPLUGIN_API FCustomMeshAsset : public FAssetTypeActions_Base
{
public:
	FCustomMeshAsset(EAssetTypeCategories::Type Type);

	// Returns the name of the asset.
	virtual FText GetName() const override;
	
	// The browsing color of the asset in the Content Browser.
	virtual FColor GetTypeColor() const override;
	
	// The class corresponding to this action, which in this case is OurAssetObject.
	virtual UClass* GetSupportedClass() const override;
	
	// Used to define the editor to display after opening, our future main battlefield.
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;

	// Gets the directory for creating assets.
	virtual uint32 GetCategories() override;
	
private:
	EAssetTypeCategories::Type AssetCategory;
		
};
