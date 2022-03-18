if (myIssues->empty())
    return;

dc.SetBrush(*wxWHITE_BRUSH);
dc.SetPen(wxPen(lightGrey));

dc.DrawRectangle(leftBorder,upperBorder,
            nameWidth + (pixelPerDay * lastDate.Subtract(firstDate).GetDays())
                + (2 * textBorder),
            ((textHeight + textDistance) * (2 + myIssues->size())));

DrawLines(dc);
DrawGrid(dc);
DrawMilestones(dc);
DrawIssues(dc);
DrawIssuesText(dc);
DrawDependencies(dc);
