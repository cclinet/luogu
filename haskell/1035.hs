main :: IO ()
main = do
  input <- getLine
  let number = read input :: Int
  let target = fromIntegral number :: Double
  let sum_harmonic :: Int -> Double -> Int
      sum_harmonic k sn
        | sn > target = k - 1
        | otherwise = sum_harmonic (k + 1) (sn + (1 / fromIntegral k))
  print (sum_harmonic 1 0)
