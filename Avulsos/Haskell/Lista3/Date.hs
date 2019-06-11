data Day = Dia Int deriving (Eq,Ord,Show)
newDia :: Int -> Day
newDia x = Dia x

instance Bounded Day where
    minBound = Dia 1
    maxBound = Dia 31

data Month = Mes Int
newMes :: Int -> Month
newMes x | mod x 13 == 0 = Mes 1
         | otherwise = Mes (mod x 13)

instance Eq Month where
   Mes x == Mes y = (if x == y then True else False)
   
instance Ord Month where
   compare (Mes x) (Mes y)
        | x < y = LT
        | x > y = GT
        | x == y = EQ

instance Show Month where
   show (Mes x) = (meses !! (x-1))

instance Bounded Month where
   minBound = Mes 1
   maxBound = Mes 12

meses = ["Janeiro","Fevereiro","Marco","Abril","Maio","Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"]

data Year = Ano Int deriving (Eq,Ord,Show)
newAno :: Int -> Year
newAno x | x < 0 = Ano 0
         | otherwise = Ano x

data Date = Data Day Month Year
newDate :: Int -> Int -> Int -> Date
newDate x y z = Data (newDia x) (newMes y) (newAno z)

