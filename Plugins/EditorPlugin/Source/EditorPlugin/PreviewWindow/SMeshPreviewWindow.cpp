#include "SMeshPreviewWindow.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SMeshPreviewWindow::Construct(const FArguments& InArgs)
{
	SEditorViewport::Construct(SEditorViewport::FArguments());
}

void SMeshPreviewWindow::OnFocusViewportToSelection()
{
	SEditorViewport::OnFocusViewportToSelection();
}

TSharedRef<FEditorViewportClient> SMeshPreviewWindow::MakeEditorViewportClient()
{
	TSharedRef<FEditorViewportClient> EditorViewportClient = MakeShareable(new FEditorViewportClient(nullptr));
	return EditorViewportClient;
}

TSharedPtr<SWidget> SMeshPreviewWindow::MakeViewportToolbar()
{
	return SEditorViewport::MakeViewportToolbar();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION