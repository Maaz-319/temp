# Website Hosting Options

**Prepared for:** Website hosting decision  
**Website:** Next.js website (currently static)  
**Domain:** Registered with GoDaddy

## 1. Overview

We can keep the domain registered with GoDaddy and host the website somewhere else. The domain is the website's address; hosting is where the website runs.

There are two possible needs:

- **Static website:** Suitable for pages that mainly display information, images, and services.
- **Dynamic website:** Needed if we later connect the site to shopify.

## 2. Options for a Static Website

A static website is usually simpler to host, fast, and requires less maintenance.

### Option A: Cloudflare Pages (Recommended) (Currently Used)

**Best fit for a business website.**

- Fast delivery around the world, HTTPS security.
- Free plan available, with generous usage limits.

### Option B: Vercel

- Designed to work well with Next.js.
- Has a free plan but with limits tighter than cloudflare.
- The free plan is good for personal, non-commercial use; a commercial website generally needs a suitable paid plan.
- **Trade-off:** Commercial use and higher usage may require a paid plan.

Website: https://vercel.com/  
Plans: https://vercel.com/docs/plans

### Option C: Netlify

- Free plan has a monthly credits; usage can consume those credits.
- **Trade-off:** If the allowance is exhausted, the site is down until the allowance resets or the plan changes.

Website: https://www.netlify.com/  
Plans: https://www.netlify.com/pricing/

### Static Hosting at a Glance

| Feature | Cloudflare Pages | Vercel | Netlify |
|---|---|---|---|
| Good for static sites | Yes | Yes | Yes |
| Custom domain | Yes | Yes | Yes |
| Main consideration | Adds a 10-40ms delay on first request | Free plan is not for commercial use | Monthly credit limits |
