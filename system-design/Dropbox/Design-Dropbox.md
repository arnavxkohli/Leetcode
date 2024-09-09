# Design Dropbox

This is a dropbox design question from [IGotAnOffer](https://www.youtube.com/watch?v=4_qu1F9BXow).

## Clarifications and Requirements

### Basics

- Uploading: No restrictions, all file types are supported. The app is blind to the file type (no preview for videos).
- Downloading: Same as uploading
- Sync between devices: Mobile, web and desktop app
- Notifications
- 100M signed up users, 1M total DAU. Each user uploads 1 file a day on average.
- 1 file is 5mb, file limit is 10G or smaller. 15 G limit per user account.
- Trust and reliable: You need high availability and eventual consistency?

To sync across devices, you need to have pub/sub to the upload service. Once a new upload is made, the other devices need to ensure they queue a download.

It is NOT a backup app. There is no way to restore backups if you delete a file.

### Math

1M Users signed up x 15G per user -> 1.5PB of data per data
QPS: 11 (queries per second). At peak -> 20 QPS
Traffic: 5TB (5MB x 1M users)

### General Tips

- Don't spend too long here
- Rely on the interviewer
- If they aren't being conversational figure it out
- Get used to the keyboard shortcuts

## High Level Design Considerations:

1. Reads vs Writes?
2. S3 actually gives you versioning out of the box, talk about stuff that was off the table initially if required.
3. Read replicas, and master-slaves for writing data to the MySQL/PostgresQL DB
4. CDN - so so so important
5. Network Paritioning, replicate some of the server or database region specific
