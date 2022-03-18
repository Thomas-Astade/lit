switch (event.GetColumn())
{
    case 0: milestoneListCtrl->SortName(); break;
    case 1: milestoneListCtrl->SortEndDate(); break;
    case 2: milestoneListCtrl->SortProject(); break;
    case 3: milestoneListCtrl->SortResource(); break;
}