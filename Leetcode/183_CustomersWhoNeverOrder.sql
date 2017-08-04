SELECT Name AS Customers
FROM Customers c  left join Orders o on c.Id=o.CustomerId
WHERE o.CustomerId IS NULL;


SELECT A.Name AS Customers
from Customers A
WHERE NOT EXISTS (SELECT 1 FROM Orders B WHERE A.Id = B.CustomerId)


SELECT A.Name AS Customers
from Customers A
WHERE A.Id NOT IN (SELECT B.CustomerId from Orders B)