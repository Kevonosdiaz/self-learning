 -- Inner join everything and just apply DISTINCT when getting counts
SELECT c.company_code, c.founder, COUNT(DISTINCT l.lead_manager_code), COUNT(DISTINCT s.senior_manager_code), COUNT(DISTINCT m.manager_code), COUNT(DISTINCT e.employee_code)
FROM Company as c, Lead_Manager as l, Senior_Manager as s, Manager as m, Employee as e
WHERE c.company_code = l.company_code AND c.company_code = s.company_code AND c.company_code = m.company_code AND c.company_code = e.company_code
GROUP BY c.company_code, c.founder
ORDER BY c.company_code ASC;

-- Left join version which can prevent issues when 0 members of certain level in hierarchy
SELECT c.company_code, c.founder, COUNT(DISTINCT l.lead_manager_code), COUNT(DISTINCT s.senior_manager_code), COUNT(DISTINCT m.manager_code), COUNT(DISTINCT e.employee_code)
FROM Company as c
LEFT JOIN Lead_Manager as l ON c.company_code = l.company_code
LEFT JOIN Senior_Manager as s ON c.company_code = s.company_code
LEFT JOIN Manager as m ON c.company_code = m.company_code
LEFT JOIN Employee as e ON c.company_code = e.company_code

GROUP BY c.company_code, c.founder
ORDER BY c.company_code ASC;
