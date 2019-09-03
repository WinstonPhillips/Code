execute procedure drop_if_exists('trigger', 'tr_DEPARTMENT_RATING_update');
execute procedure drop_if_exists('trigger', 'tr_DEPARTMENT_RATING_insert');
execute procedure drop_if_exists('trigger', 'tr_DEPARTMENT_RATING_delete');

commit  work;

set term #;

create trigger tr_DEPARTMENT_RATING_update for DEPARTMENT_TESTER after UPDATE
as
DECLARE old_rating varchar(5);
DECLARE new_rating varchar(5);
begin
select RATING from f_rating(OLD.budget) into :old_rating; 
select RATING from f_rating(NEW.budget) into :new_rating;

update DEPARTMENT_RATING
set OCCURRENCES = OCCURRENCES - 1
where :old_rating = RATING;

update DEPARTMENT_RATING
set OCCURRENCES = OCCURRENCES + 1
where :new_rating = RATING;

end # 

set term #;

commit work;
--test
update DEPARTMENT_TESTER
set BUDGET = 160000
where DEPT_NO = 120;

commit work;

select * from DEPARTMENT_RATING;

set term #;



