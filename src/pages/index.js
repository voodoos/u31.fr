import React from "react"
const Layout = require('../components/layout/Layout.bs.js').make;
const Posts = require('../components/blog/Posts.bs.js').make;

export default ({ data }) => {
  console.log(data);
  return <Layout> <Posts articles={data.articles.edges} /> </Layout>
};

export const query = graphql`
query {
  articles: allFile(filter: {sourceInstanceName: {eq: "articles"}, extension: {eq: "md"}}) {
    edges {
      node {
        childMarkdownRemark {
          html
          frontmatter {
            date
            title
          }
          timeToRead
          id
        }
      }
    }
  }
  critics: allFile(filter: {sourceInstanceName: {eq: "pages"}, extension: {eq: "md"}}) {
    edges {
      node {
        childMarkdownRemark {
          html
          frontmatter {
            date
            title
          }
          timeToRead
          id
        }
      }
    }
  }
}
`



/*
let default = props => {
  Js.log(props);
  <Layout> <Posts articles={props##data##allFile##edges} /> </Layout>;
};

// todo: bindings ? graphql ppx ?
%raw
{|export const query = graphql`
query {
  allFile(filter: {sourceInstanceName: {eq: "articles"}, extension: {eq: "md"}}) {
    edges {
      node {
        childMarkdownRemark {
          html
          frontmatter {
            date
            title
          }
          timeToRead
          id
        }
      }
    }
  }
}
`|};*/