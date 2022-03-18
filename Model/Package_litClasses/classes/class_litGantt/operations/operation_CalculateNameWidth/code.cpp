nameWidth = 0;
for (unsigned int i = 0; i < myIssues->size(); i++)
{
    int x,y;
    dc.GetTextExtent((*myIssues)[i]->GetName(),&x,&y);
    if (x > nameWidth)
        nameWidth = x;
}