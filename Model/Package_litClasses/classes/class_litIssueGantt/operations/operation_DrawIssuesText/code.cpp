for (unsigned int i = 0; i < myIssues->size(); i++)
{
    if (i == static_cast<unsigned>(selectedItem))
        dc.SetTextForeground(*wxRED);
    else
        dc.SetTextForeground(*wxBLACK);
    int y = 2 + upperBorder + 2*(textHeight + textDistance) + i*(textHeight+textDistance);
    dc.DrawText((*myIssues)[i]->GetName(),leftBorder + textBorder,y);
}

dc.SetTextForeground(*wxBLACK);
