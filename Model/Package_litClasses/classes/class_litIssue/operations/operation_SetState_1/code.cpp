if ((state == 0) && (start <= wxDateTime::Today()))
    state = 1; // planned -> started

if ((state == 1) && (end < wxDateTime::Today()))
    state = 2; // started -> delayed

if ((state == 2) && (end >= wxDateTime::Today()))
    state = 1; // delayed -> started

if ((state == 1) && (start > wxDateTime::Today()))
    state = 0; // started -> planned