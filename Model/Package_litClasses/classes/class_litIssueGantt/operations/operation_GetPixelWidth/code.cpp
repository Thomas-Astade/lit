return leftBorder + rightBorder + nameWidth 
        + (pixelPerDay * lastDate.Subtract(firstDate).GetDays())
        + (2 * textBorder);