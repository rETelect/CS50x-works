
SELECT description FROM crime_scene_reports
WHERE year = 2023 AND month = 7 AND day = 28
AND street = 'Humphrey Street';


SELECT license_plate FROM bakery_security_logs
WHERE year = 2023 AND month = 7 AND day = 28
AND hour = 10 AND minute >= 15 AND minute <= 25 AND activity = 'exit';


SELECT account_number FROM atm_transactions
WHERE year = 2023 AND month = 7 AND day = 28
AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';


SELECT caller, receiver FROM phone_calls
WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60;


SELECT id, hour, minute FROM flights
WHERE origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville')
AND year = 2023 AND month = 7 AND day = 29
ORDER BY hour, minute LIMIT 1;


SELECT name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
JOIN phone_calls ON people.phone_number = phone_calls.caller
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE bakery_security_logs.year = 2023 AND bakery_security_logs.month = 7 AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10 AND bakery_security_logs.minute >= 15 AND bakery_security_logs.minute <= 25
AND phone_calls.year = 2023 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration < 60
AND passengers.flight_id = 36
AND bank_accounts.account_number IN (SELECT account_number FROM atm_transactions WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw');


SELECT city FROM airports
WHERE id = (SELECT destination_airport_id FROM flights WHERE id = 36);


SELECT name FROM people
WHERE phone_number = (SELECT receiver FROM phone_calls WHERE caller = (SELECT phone_number FROM people WHERE name = 'Bruce') AND year = 2023 AND month = 7 AND day = 28 AND duration < 60);
