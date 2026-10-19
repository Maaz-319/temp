# Website Hosting Options

**Prepared for:** Website hosting decision  
**Website:** Next.js website (currently static)  
**Domain:** Registered with GoDaddy

## 1. Overview

We can keep the domain registered with GoDaddy and host the website somewhere else. The domain is the website's address; hosting is where the website runs.

There are two possible needs:

- **Static website:** Suitable for pages that mainly display information, images, and services.
- **Dynamic website:** Needed if the site later requires features such as an admin panel, customer accounts, bookings, or a database.

## 2. Options for a Static Website

A static website is usually simpler to host, fast, and requires less maintenance.

### Option A: Cloudflare Pages

**Best fit for a simple business website.**

- Fast delivery around the world, HTTPS security, and automatic updates from our code repository.
- Supports a custom domain.
- Free plan available, with usage and build limits.
- **Trade-off:** Some advanced Next.js features will not work unless the site is configured for a dynamic hosting setup.

Website: https://pages.cloudflare.com/  
Next.js setup guide: https://developers.cloudflare.com/pages/framework-guides/nextjs/deploy-a-static-nextjs-site/

### Option B: Vercel

**Best fit for the easiest Next.js deployment experience.**

- Designed to work well with Next.js.
- Automatic deployments, preview links, HTTPS, and custom domains.
- The free Hobby plan is intended for personal, non-commercial use; a client's commercial website generally needs a suitable paid plan.
- **Trade-off:** Commercial use and higher usage may require a paid plan.

Website: https://vercel.com/  
Plans: https://vercel.com/docs/plans

### Option C: Netlify

**Another good option for static websites.**

- Automatic deployments, HTTPS, custom domains, and preview links.
- Includes tools for adding forms and server-side functions.
- Free plan has a monthly credit allowance; usage can consume those credits.
- **Trade-off:** If the allowance is exhausted, the site may pause until the allowance resets or the plan changes.

Website: https://www.netlify.com/  
Plans: https://www.netlify.com/pricing/

### Static Hosting at a Glance

| Feature | Cloudflare Pages | Vercel | Netlify |
|---|---|---|---|
| Good for static sites | Yes | Yes | Yes |
| Custom domain | Yes | Yes, subject to plan terms | Yes |
| Automatic updates | Yes | Yes | Yes |
| Future dynamic features | Possible with additional setup or migration | Strong Next.js support | Possible with functions and other services |
| Main consideration | Next.js static-export requirements | Free plan is not for commercial use | Monthly credit limits |

## 3. Options for a Dynamic Website

A dynamic website can do more than display information. For example, it can let staff update content, store customer details, accept bookings, or manage products.

### Option A: Cloudflare Workers

**Recommended if we want to build on the Cloudflare platform.**

- Can run the website's server-side features and APIs.
- Can connect to a database and file storage when needed.
- Cloudflare also offers domain, security, and performance services.
- Free usage is limited; higher usage or resources may require a paid plan.
- **Trade-off:** Setup is more technical, and we must confirm that the Next.js features used by the website are supported by the chosen deployment method.

Website: https://workers.cloudflare.com/  
Documentation: https://developers.cloudflare.com/workers/

### Option B: Vercel + Database

**Recommended if ease of working with Next.js is the priority.**

- Supports server-side pages and backend functions.
- Can connect to separate database, login, and storage services.
- Deployment is straightforward for many Next.js projects.
- The commercial website generally needs a suitable paid Vercel plan; additional services may have separate limits or charges.
- **Trade-off:** Parts of the system may be managed through different providers.

Website: https://vercel.com/  
Documentation: https://vercel.com/docs

### Option C: Netlify + Database or Other Services

**Another option for a website with backend features.**

- Supports server-side functions and integrations.
- Can connect to databases and other services.
- The free plan has a monthly credit allowance shared across metered usage.
- **Trade-off:** A site with heavier usage may need a paid plan or separate services.

Website: https://www.netlify.com/  
Documentation: https://docs.netlify.com/

## 4. What Might Require a Dynamic Website?

| Possible feature | What it may need |
|---|---|
| Contact form that sends a message | A form service or backend function |
| Staff can edit website content | An admin panel and content storage or a CMS |
| Customer login | Authentication and server-side functionality |
| Bookings, orders, or product management | Backend functionality and a database |
| File or image uploads | File storage |

We do not need to build all of these now. We can add features when the business needs them.

## 5. Connecting the GoDaddy Domain

**The domain can stay at GoDaddy regardless of which hosting provider we choose.** There is no need to transfer ownership.

We have two choices:

### Choice A: Keep GoDaddy DNS

We add the hosting provider's required DNS records in GoDaddy.

- Fewer changes to the existing setup.
- Existing email settings can remain in place if preserved correctly.
- Cloudflare's full DNS and proxy features are not automatically enabled just by hosting on Cloudflare Pages or Workers.

### Choice B: Use Cloudflare DNS

We keep the domain registered at GoDaddy but let Cloudflare manage its DNS.

- Website routing and supported security features can be managed through Cloudflare.
- A convenient choice if we use Cloudflare hosting.
- Existing DNS records, especially email records, must be copied and checked before changing nameservers.

Guides:
- GoDaddy DNS: https://www.godaddy.com/en/help/manage-dns-records-680
- Cloudflare DNS setup: https://developers.cloudflare.com/dns/zone-setups/full-setup/setup/

After setup, we should check that the main domain and `www` address work, HTTPS is enabled, and existing email services still function.

## 6. Recommendation

- **If the website will remain informational:** Start with **Cloudflare Pages**.
- **If the website will need a custom backend later:** Consider **Cloudflare Workers** and add a database or other services only when needed.
- **If the simplest Next.js deployment experience matters most:** Consider **Vercel**, with a plan suitable for commercial use.

The final choice should depend on the features the client expects, rather than choosing a platform based on hosting alone. Free plans have limits, and their terms can change, so we should confirm the current terms before launch.

## 7. One Question for the Client

**Will you need to update website content yourself through an admin panel, or will you ask us to make changes when needed?**

This helps determine whether a simple static website is enough or whether we should plan for a content management system or custom backend.
