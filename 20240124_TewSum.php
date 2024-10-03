<?php
function returnSumNums($nums, $target)
{
    for ($i = 1; $i < sizeof($nums); $i++)
    {
        for ($j = 1; $j < sizeof($nums); $j++)
        {
            if ($i != $j && $nums[$i] + $nums[$j] == $target)
            {
                return [$nums[$i], $nums[$j]];
            }
        }
    }
    return [];
}

$numsLine   = fgets(STDIN); // numsを取得
$target = fgets(STDIN); // targetを取得
$nums       = substr($numsLine, 1, strlen($numsLine) - 2);
$nums       = explode(",", $nums);
foreach ($nums as $num)
{
    echo $num . ",";
}
$sumNums = returnSumNums($nums, $target);
$return  = "[";
for ($i = 0; $i < sizeof($sumNums); $i++)
{
    $return .= $sumNums[$i];
    if ($i < sizeof($sumNums) - 1)
    {
        $return .= ",";
    }
}
$return .= "]";
echo $return;