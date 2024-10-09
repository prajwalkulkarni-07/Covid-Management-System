## This is a C++ OOPS based project in which we store data of centers eligible for vaccinating people, and making the list available to the public. People can search vaccination centers according to their convenience and get vaccinated.

## Key Features:
1. User Registration and Login: Users can sign up by entering their name, phone number, and password. The login system checks the provided credentials against stored user data.
2. Vaccine Slot Availability: The system displays available slots for each vaccine at different centers. The availability decreases as users book their slots.
3. Vaccines and Centers: Three vaccines are supported: Covaxin, Covishield, and Pfizer. Each vaccine has a predefined set of centers in Hubli-Dharwad with an initial stock that decreases as vaccinations are booked.
4. Eligibility Check: The program checks the user's eligibility based on their age and location. If a user is under 18 or outside the Hubli-Dharwad region, they are not allowed to proceed with the booking.
5. Custom Exceptions: The code uses custom exceptions to handle specific errors, such as when a user is not registered or if they are ineligible due to age constraints.
6. Guidelines: After a successful booking, the system provides users with guidelines to follow on vaccination day.
