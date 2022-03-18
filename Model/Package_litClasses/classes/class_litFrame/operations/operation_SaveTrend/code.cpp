wxBitmap aBitmap(10,10);
wxMemoryDC dc;
dc.SelectObject(aBitmap);

issueTrend->SetSelectedItem(-1);
issueTrend->CalculateTimeBoundaries();
issueTrend->CalculateTextHeight(dc);

wxBitmap theBitmap(issueTrend->GetPixelWidth(), issueTrend->GetPixelHeight());

dc.SelectObject(theBitmap);

dc.SetBackground(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("WHITE"), wxSOLID));
dc.Clear();

issueTrend->DoDraw(dc);

dc.SelectObject(wxNullBitmap);
SaveBitmap(theBitmap);
