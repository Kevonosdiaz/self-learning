-- Get challenges solved by hacker, only take ones they got max score
-- for the associated difficulty
-- Use GROUP BY to get unique competitor listed, HAVING for at least 1 full clear
-- then ORDER BY to list by descending # of full clears, using hid for tie break
SELECT h.hacker_id, h.name
FROM Hackers h
JOIN Submissions s on s.hacker_id = h.hacker_id
JOIN Challenges c on s.challenge_id = c.challenge_id
JOIN Difficulty d on d.difficulty_level = c.difficulty_level
WHERE s.score = d.score
GROUP BY h.hacker_id, h.name
HAVING COUNT(s.challenge_id) > 1
ORDER BY COUNT(s.challenge_id) DESC, h.hacker_id ASC;
