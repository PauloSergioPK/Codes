data Pessoa = Pessoa { nome :: String
                     , idade :: Int
                     , salario :: Float 
                     } deriving (Eq,Ord)

data Criterio = ByNome | ByIdade | BySalario

sortListPessoa :: [Pessoa] -> Criterio -> [Pessoa]
sortListPessoa [] _ = []
sortListPessoa x ByNome = (quickSortNome x)
sortListPessoa x ByIdade = (quickSortIdade x) 
sortListPessoa x BySalario = (quickSortSalario x) 

quickSortNome [] = []
quickSortNome [Pessoa n i s] = [Pessoa n i s]
quickSortNome ((Pessoa n i s):xs) = a ++ [Pessoa n i s] ++ b
                where a = quickSortNome [(Pessoa x y z) | (Pessoa x y z) <- xs, x <= n]
                      b = quickSortNome [(Pessoa x y z) | (Pessoa x y z) <- xs, x > n]

quickSortIdade [] = []
quickSortIdade [Pessoa n i s] = [Pessoa n i s]
quickSortIdade ((Pessoa n i s):xs) = a ++ [Pessoa n i s] ++ b
                where a = quickSortIdade [(Pessoa x y z) | (Pessoa x y z) <- xs, y <= i]
                      b = quickSortIdade [(Pessoa x y z) | (Pessoa x y z) <- xs, y > i]

quickSortSalario [] = []
quickSortSalario [Pessoa n i s] = [Pessoa n i s]
quickSortSalario ((Pessoa n i s):xs) = a ++ [Pessoa n i s] ++ b
                where a = quickSortSalario [(Pessoa x y z) | (Pessoa x y z) <- xs, z <= s]
                      b = quickSortSalario [(Pessoa x y z) | (Pessoa x y z) <- xs, z > s]

toString [] = ""
toString [Pessoa n i s] = "Pessoa : ( " ++ n ++ ", "++show(i)++", "++show(s)++" )"
toString ((Pessoa n i s):xs) = "Pessoa : ( " ++ n ++ ", "++show(i)++", "++show(s)++" ),"++" " ++ toString xs 

instance Show Pessoa where
       show pessoa = toString [pessoa]
 