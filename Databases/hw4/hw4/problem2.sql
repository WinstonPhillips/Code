

execute procedure drop_if_exists('trigger', 'tr_DEPARTMENT_RATING_update');
execute procedure drop_if_exists('trigger', 'tr_DEPARTMENT_RATING_insert');
execute procedure drop_if_exists('trigger', 'tr_DEPARTMENT_RATING_delete');
delete from DEPARTMENT_TESTER;


commit work;
set term #;
create trigger tr_DEPARTMENT_RATING_insert for DEPARTMENT_TESTER after INSERT
as
DECLARE new_rating varchar(5);
begin 
select RATING from f_rating(NEW.budget) into :new_rating;

update DEPARTMENT_RATING
set OCCURRENCES = OCCURRENCES + 1
where :new_rating = RATING;

end #

set term #;

commit work;

insert into DEPARTMENT_TESTER(DEPT_NO, DEPARTMENT, HEAD_DEPT, MNGR_NO, BUDGET, LOCATION, PHONE_NO) select * from DEPARTMENT;

commit work;
select * from DEPARTMENT_RATING;

set term #;







