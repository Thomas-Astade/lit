wxPaintDC dc(this);
DoPrepareDC(dc);

if (myIssues->empty())
    return;

CalculateTimeBoundaries();
SetVirtualSize(GetPixelWidth(), GetPixelHeight());
CalculateTextHeight(dc);

DoDraw(dc);
