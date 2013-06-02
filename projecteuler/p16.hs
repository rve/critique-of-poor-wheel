import Data.Char
test = 2^10::Integer
indata = 2^1000::Integer
cal xs = foldl (\y x-> y + (ord x) - (ord '0')) 0 xs
ans xs  = cal $ show xs