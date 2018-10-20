import System.Random
import Data.Array
import Data.Foldable (traverse_)

firstNames :: Array Int String
firstNames = listArray (0, 15)
    [ "Andrew"
    , "Steven"
    , "Michael"
    , "Roger"
    , "Penny"
    , "Susan"
    , "Blake"
    , "Evelyn"
    , "Joel"
    , "Gabby"
    , "Ian"
    , "Sean"
    , "Michelle"
    , "Roslyn"
    , "Patricia"
    , "Simon"
    ]

firstPartSurname :: Array Int String
firstPartSurname = listArray (0, 9)
    [ "Bloom"
    , "Blue"
    , "Red"
    , "Green"
    , "Wood"
    , "King"
    , "Knight"
    , "Vander"
    , "Fitz"
    , "Vester"
    ]

secondPartSurname :: Array Int String
secondPartSurname = listArray (0, 14)
    [ "field"
    , "drop"
    , "hart"
    , "croft"
    , "low"
    , "sly"
    , "smith"
    , "son"
    , "ston"
    , "berg"
    , "cock"
    , "cox"
    , "garden"
    , "stein"
    , "sen"
    ]

departments :: Array Int String
departments = listArray (0, 10)
    [ "Economics"
    , "Business"
    , "Medicine"
    , "Arts"
    , "Humanities"
    , "Social science"
    , "Pathology"
    , "Computer science"
    , "Dentistry"
    , "Law"
    , "Engineering"
    ]

--main :: IO ()
--main = traverse_ go [0..999] where go n = do
--    firstN <- (firstNames !) <$> randomRIO (0, 15)
--    secondN <- (firstPartSurname !) <$> randomRIO (0, 9)
--    thirdN <- (secondPartSurname !) <$> randomRIO (0, 14)
--    dept <- (departments !) <$> randomRIO (0, 10)
--    cgpa <- randomRIO (0, 10) :: IO Double
--    gradYear <- (randomRIO (2018, 2022)) :: IO Int
--    putStrLn (firstN ++ " " ++ secondN ++ thirdN ++ "," ++
--        dept ++ "," ++ show cgpa ++ "," ++ show n ++ "," ++ show gradYear)

main = traverse_ go [0..999] where 
    go n = do
        mark1 <- (randomRIO (0, 100)) :: IO Int
        mark2 <- (randomRIO (0, 100)) :: IO Int
        mark3 <- (randomRIO (0, 100)) :: IO Int
        putStrLn $ show n ++ "," ++ show mark1 ++ "," ++ show mark2 ++ "," ++ show mark3
