#pragma once
#include "Editor/UnrealEd/Public/SCommonEditorViewportToolbarBase.h"
#include "Editor/UnrealEd/Public/SEditorViewport.h"
#include "Runtime/CoreUObject/Public/UObject/GCObject.h"


class EDITORPLUGIN_API SMeshPreviewWindow : public SEditorViewport
{
public:

	SLATE_BEGIN_ARGS(SMeshPreviewWindow)
	{
		
	}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	/** Begin SViewport Interface */
	// This function implements behavior when focusing, i.e., what to do when pressing F. Are people still developing games with controllers?
	virtual void OnFocusViewportToSelection() override;
	// Add a ViewportClient class, one of the core parts we need to handle.
	virtual TSharedRef<FEditorViewportClient> MakeEditorViewportClient() override;
	// Create the Toolbar.
	virtual TSharedPtr<SWidget> MakeViewportToolbar() override;

	/** End SViewport Interface */
};
