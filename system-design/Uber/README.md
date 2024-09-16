# Design Uber

Uber is a ride sharing service that connects users to drivers and allows them to find a ride. It is a user-facing product.

## Requirements

### Functional Requirements (Users can...)

- Users should be able to enter start/end locations and get estimated fares.
- Users should be able to request rides (to nearby available drivers in real-time).
- Drivers should be able to accept/deny rides and navigate to pick-up/drop-off

Out of scope: Multiple car types, Ratings for drivers/riders, Schedule a ride.

###  Non-Functional Requirements (ilities...)

Don't write down buzz-words. Identify qualities unique to this system.

- Low latency (< 1 min) to match or failure.
- Ride to driver is 1-1 (consistency).
- High availabile outside of matching (minimize downtime)
- Adjust for surge times, handle high throughput (surges, peak hours - football game).
  `100,000 rps`

Out of scope: GDPR/User privacy, resilience and handling system failures. Monitoring/Data analytics, logging, alerting, CI/CD pipelines.

## Back of the Envelope calculations

We didn't do these because they don't really give you much to go on. "Ok, so it's a lot". It is more often than not a scaled system with horizontal scaling. Delay these calculations for during the the HLD. Only do them if the result actually affects the design. (It is my preference to forego them for now).

## Core Entities

- Ride (ETA, Price)
- Riders
- Users
- Location (less obvious) -> Locations of all riders.

## APIs

### `/api/ride/fare-estimate`

- Method: `POST`
- Request:

    ```javascript
    {
        source: String,
        destination: String
    }
    ```

- Response: `200`, `40x`, `50x`

    ``` javascript
    {
        ride_id: Integer,
    }
    ```

### `/api/ride/request`

- Method: `PATCH`
- Request:

    ```javascript
    {
        ride_id: Integer
    }
    ```

- Response: `N/A`

### `/api/location/update`

- Method: `POST`
- Request:

    ```javascript
    {
        lat: Integer,
        long: Integer
    }
    ```

- Response: `N/A`

### `/ride/driver/accept`

- Method: `PATCH`
- Request:

    ```javascript
    {
        ride_id: Integer,
        accept: Boolean
    }
    ```

- Response: `N/A`

### `/ride/driver/update`

- Method: `PATCH`
- Request:

    ``` javascript
    {
        ride_id: Integer,
        status: PickedUp || DroppedOff
    }
    ```

- Response: `NULL` if `DroppedOff`

    ``` javascript
    {
        lat: Integer,
        long: Integer
    }
    ```

Important consideration here: There is a reason `user_id` is not included in any of the API calls. This discourages spoofing of the `user_id`, and ensures good API security. The `user_id` can be included with the JWT token, during the request or with the session token when the request is first made.
