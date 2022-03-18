wxBitmap aBitmap(10,10);
wxMemoryDC dc;
dc.SelectObject(aBitmap);

issueGantt->SetSelectedItem(-1);
issueGantt->CalculateTimeBoundaries();
issueGantt->CalculateTextHeight(dc);
issueGantt->CalculateNameWidth(dc);

wxBitmap theBitmap(issueGantt->GetPixelWidth(dc), issueGantt->GetPixelHeight());

dc.SelectObject(theBitmap);
dc.SetBackground(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("WHITE"), wxSOLID));
dc.Clear();

issueGantt->DoDraw(dc);

dc.SelectObject(wxNullBitmap);
SaveBitmap(theBitmap);
