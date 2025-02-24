"use client";

import { Button, buttonVariants } from "@/components/ui/button";
import { Card } from "@/components/ui/card";
import { siteConfig } from "@/config/site";
import { ArrowRight } from "lucide-react";
import Image from "next/image";
import Link from "next/link";
import { FaGithub, FaLinkedin, FaTwitter } from "react-icons/fa";

const recentPosts = [
  {
    title: "Building Modern Web Applications",
    date: "April 15, 2024",
    excerpt:
      "Exploring the latest trends and best practices in web development...",
    slug: "building-modern-web-applications",
  },
  {
    title: "The Future of Frontend Development",
    date: "April 10, 2024",
    excerpt:
      "Discussing emerging technologies and frameworks that are shaping...",
    slug: "future-of-frontend-development",
  },
  {
    title: "Mastering TypeScript",
    date: "April 5, 2024",
    excerpt: "A comprehensive guide to using TypeScript in your projects...",
    slug: "mastering-typescript",
  },
];

const IntroSection = () => (
  <div className="flex gap-12 items-center mb-20">
    <div className="space-y-6 flex-1">
      <div className="space-y-2">
        <h2 className="text-sm uppercase tracking-wider text-primary/60 ">
          I&apos;m{" "}
          <a
            href={siteConfig.links.github}
            target="_blank"
            className="hover:border-primary text-xl border-b border-primary/80  text-primary  "
          >
            Singhastra
          </a>
        </h2>
        <h1 className="text-4xl md:text-5xl font-bold leading-tight">
          Learning
          <br />
          & Writing about
          <br />
          <span className="text-primary/80">technologies</span>
        </h1>
      </div>
      <p className="text-lg text-muted-foreground">Full Stack Web Developer</p>
      <div className="flex gap-4">
        <Link href="/blogs" className={buttonVariants({ variant: "default" })}>
          Read Blog <ArrowRight className="ml-2 h-4 w-4" />
        </Link>
        <Link href="/about" className={buttonVariants({ variant: "outline" })}>
          About Me
        </Link>
      </div>
    </div>
    <div className="relative h-[400px]  flex-1 rounded-lg overflow-hidden  border-double border-4 ">
      <Image
        src="https://images.unsplash.com/photo-1498050108023-c5249f4df085?auto=format&fit=crop&q=80"
        alt="Coding Environment"
        fill
        className="object-cover"
      />
      <div className="absolute inset-0 bg-gradient-to-tr from-background/80 to-transparent" />
    </div>
  </div>
);

export default function Home() {
  return (
    <div className="min-h-screen">
      <div className="container mx-auto px-4 py-16 max-w-4xl">
        <IntroSection />

        {/* Recent Posts Section */}
        <section className="mb-20">
          <h2 className="text-3xl font-bold mb-8">Recent Posts</h2>
          <div className="grid gap-6">
            {recentPosts.map((post) => (
              <div key={post.slug}>
                <Card className="p-6 hover:shadow-lg transition-shadow">
                  <h3 className="text-xl font-semibold mb-2">
                    <Link
                      href={`/blog/${post.slug}`}
                      className="hover:text-primary"
                    >
                      {post.title}
                    </Link>
                  </h3>
                  <p className="text-sm text-muted-foreground mb-3">
                    {post.date}
                  </p>
                  <p className="text-muted-foreground">{post.excerpt}</p>
                </Card>
              </div>
            ))}
          </div>
        </section>

        {/* Footer */}
        <footer className="border-t pt-8 text-center">
          <div className="flex justify-center gap-6 mb-6">
            <Button variant="ghost" size="icon" asChild>
              <Link href="https://twitter.com" target="_blank">
                <FaTwitter className="h-5 w-5" />
                <span className="sr-only">Twitter</span>
              </Link>
            </Button>
            <Button variant="ghost" size="icon" asChild>
              <Link href="https://github.com" target="_blank">
                <FaGithub className="h-5 w-5" />
                <span className="sr-only">GitHub</span>
              </Link>
            </Button>
            <Button variant="ghost" size="icon" asChild>
              <Link href="https://linkedin.com" target="_blank">
                <FaLinkedin className="h-5 w-5" />
                <span className="sr-only">LinkedIn</span>
              </Link>
            </Button>
          </div>
          <p className="text-sm text-muted-foreground">
            © {new Date().getFullYear()} John Doe. All rights reserved.
          </p>
        </footer>
      </div>
    </div>
  );
}
