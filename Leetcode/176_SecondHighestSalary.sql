# Write your MySQL query statement below
#If there is no second highest salary, then the query should return null
SELECT max(Salary)
From Employee
WHERE Salary not in (SELECT max(Salary) FROM Employee )