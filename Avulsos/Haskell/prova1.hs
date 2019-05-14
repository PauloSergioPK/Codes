-- NOME: Paulo Sergio Rabelo Costa
-- CURSO: Ciencia da Computacao
-- MATRICULA: 422218

----------
-- quest 1
----------

lsDig :: Integral t => t -> [t]
lsDig n = reverse (listaDig n)
         
isPanDig :: Integral t => t -> Bool
isPanDig n = isPanDig' (lsDig n)

--lsPanDig :: (Eq a, Integral t, Num a) => a -> [t]
lsPanDig n | n == 0 = []
           | otherwise = take n [x | x <- [0..] , isPanDig x == True]

frequencia [] _ = 0
frequencia (x:xs) n | x == n = 1 + frequencia xs n
                    | otherwise = frequencia xs n

listaDig n | n == 0 = []
           | otherwise = [mod n 10] ++ listaDig (div n 10)

isPanDig' [] = True
isPanDig' (x:xs) | frequencia xs x > 0 = False
                 | otherwise = isPanDig' xs 

----------
-- quest 2
----------

rmFirst :: Eq a => [a] -> a -> [a]
rmFirst [] _ = []
rmFirst (x:xs) n | x == n = xs
                 | otherwise = x: rmFirst xs n

minMaxSort :: Ord t => [t] -> [t]
minMaxSort [] = []
minMaxSort [x] = [x]
minMaxSort xs = [minimum xs]++minMaxSort (b)++[maximum xs]
          where a = rmFirst xs (minimum xs)
                b = rmFirst a (maximum a)
----------
-- quest 3
----------

swap :: [a] -> Int -> Int -> [a]
swap _ _ _ = []

nextPerm :: Ord a => [a] -> [a]
nextPerm     _ = []

----------
-- quest 4
----------

rmChar :: Eq t => [t] -> t -> [t]
rmChar [] _ = []
rmChar (x:xs) n | x == n = rmChar xs n
                | otherwise = x: rmChar xs n

unique :: Eq t => [t] -> [t]
unique [] = []
unique (x:xs) = x:unique (rmChar xs x)

freqChar :: (Eq a, Num b) => [a] -> [(a, b)]
freqChar [] = []
freqChar (x:xs) = [(x,frequencia (x:xs) x)] ++ freqChar (rmChar (x:xs) x)

