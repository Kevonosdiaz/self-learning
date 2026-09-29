-- LIMIT 1 here counts # of all tied top earners since GROUP BY collapses them into one entry that can be counted still
SELECT e1.salary * e1.months AS earnings, COUNT(1)
FROM Employee as e1
GROUP BY earnings
ORDER BY earnings DESC
LIMIT 1;
