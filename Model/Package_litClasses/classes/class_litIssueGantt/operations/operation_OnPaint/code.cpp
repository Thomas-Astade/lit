wxPaintDC dc(this);
DoPrepareDC(dc);

if (myIssues->empty())
    return;

CalculateTimeBoundaries();
CalculateTextHeight(dc);
CalculateNameWidth(dc);

SetVirtualSize(GetPixelWidth(dc), GetPixelHeight());

DoDraw(dc);
