type Row = [Float]
data Matrix = Matrix { nrows :: Int, ncols :: Int, rows :: [Row]} 

zeroMatrix :: Int -> Int -> Matrix
zeroMatrix x y | (x < 0) || (y < 0) = error "Matrix invalida"
               | otherwise = Matrix x y z
                         where z = take x (repeat k)
                               k = take y (repeat (0) :: Row)

intMatrix :: Int -> Int -> Matrix
intMatrix x y | (x < 0) || (y < 0) = error "Matrix invalida"
              | otherwise = Matrix x y z
                         where z = take x (repeat k)
                               k = take y (repeat (1) :: Row)

anyMatrix :: Int -> Int -> Float -> Matrix
anyMatrix x y n | (x < 0) || (y < 0) = error "Matrix invalida"
                | otherwise = Matrix x y z
                         where z = take x (repeat k)
                               k = take y (repeat (n) :: Row)

identMatrix :: Int -> Matrix
identMatrix x = Matrix x x (crossMatrix 0 x)

crossMatrix i t | i == (t-1) = [(matrixLine t i)]
                | otherwise = [(matrixLine t i)] ++ crossMatrix (i+1) t

matrixLine x i  = (take i z) ++ [1] ++ (drop (i+1) z)
             where z = take x (repeat (0) :: Row) 

sumMatrix :: Matrix -> Matrix -> Matrix
sumMatrix (Matrix n c (a:as)) (Matrix n2 c2 (b:bs)) = Matrix n c (sum' (a:as) (b:bs))  

sum' :: [Row] -> [Row] -> [Row]
sum' [] [] = []
sum' (a:as) (b:bs) = [(zipWith (+) a b)] ++ (sum' as bs)

prodScalar :: Float -> Matrix -> Matrix
prodScalar v (Matrix n c (a:as)) = Matrix n c (prod' (a:as) v)

prod' :: [Row] -> Float -> [Row]
prod' [] _ = []
prod' (a:as) n = [map (*n) a] ++ (prod' as n)

prodMatrix :: Matrix -> Matrix -> Matrix
prodMatrix (Matrix n c (as)) (Matrix n2 c2 (bs)) = Matrix n c2 (prodMatrix' as (allColum bs 0))

multi' :: Row -> Row -> Float
multi' [] [] = 0
multi' (a:as) (b:bs) = (a * b) + (multi' as bs) 

prodMatrix' :: [Row] -> [Row] -> [Row]
prodMatrix' [] _ = []
prodMatrix' (a:as) (bs) = z ++ prodMatrix' as bs
                where z = [prodMatrix'' a bs 0] 

prodMatrix'' :: Row -> [Row] -> Int -> Row
prodMatrix'' a bs i | i == length bs = [] 
                    | otherwise = [(multi' a (bs !! i))] ++ prodMatrix'' a bs (i+1)

columMatrix :: [Row] -> Int -> Row
columMatrix [] _ = []
columMatrix [a] i = [(a !! i)]
columMatrix (a:as) i = [a !! i] ++ columMatrix as i

allColum :: [Row] -> Int -> [Row]
allColum (as) i | i == length (as) = []
                | otherwise = [x] ++ allColum as (i+1)
                where x = columMatrix as i

listToMatrix :: [Row] -> Matrix
listToMatrix r = Matrix (length r) (length (r !! 0)) r

toString :: Matrix -> String
toString (Matrix n c []) = ""
toString (Matrix n c ([]:as)) = "\n" ++ toString (Matrix n c as)
toString (Matrix n c ((a:s):as)) = "("++show(a)++") "++ toString (Matrix n c (s:as)) 

instance Show Matrix where
     show matrix = toString matrix