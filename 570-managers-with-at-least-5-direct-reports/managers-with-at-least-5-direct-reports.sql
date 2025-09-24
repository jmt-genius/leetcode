select a.name from Employee a where a.id in (select b.managerId from Employee b group by b.managerId having count(b.id)>=5);
