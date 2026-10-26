-- Write your MySQL query statement below
SELECT sub.event_day as day, sub.emp_id, SUM(sub.total_time) as total_time
FROM (
    SELECT e.event_day as event_day, e.emp_id as emp_id, (e.out_time - e.in_time) as total_time
    FROM Employees e
) as sub
GROUP BY sub.event_day, sub.emp_id;
