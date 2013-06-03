myLength [] = 0
myLength (x:xs) = if xs /= []
                  then 1 + myLength xs
                  else 1